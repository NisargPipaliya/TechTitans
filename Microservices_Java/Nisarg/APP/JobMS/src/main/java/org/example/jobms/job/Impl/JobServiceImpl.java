package org.example.jobms.job.Impl;

import org.example.jobms.job.Job;
import org.example.jobms.job.JobRepo;
import org.example.jobms.job.JobService;
import org.example.jobms.job.clients.CompanyClient;
import org.example.jobms.job.clients.ReviewClient;
import org.example.jobms.job.dto.JobDTO;
import org.example.jobms.job.external.Company;
import org.example.jobms.job.external.Review;
import org.example.jobms.job.mapper.JobMapper;
import org.springframework.core.ParameterizedTypeReference;
import org.springframework.http.HttpMethod;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Service;
import org.springframework.web.client.RestTemplate;

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

@Service
public class JobServiceImpl implements JobService {
    JobRepo jobrepo;
//    RestTemplate restTemplate;
//    String companyUrl = "http://CompanyMS:8081/companies/";
//    String reviewUrl = "http://ReviewMS:8083/reviews?companyId=";
    private final CompanyClient companyClient;
    private final ReviewClient reviewClient;
    public JobServiceImpl(JobRepo repo,CompanyClient companyClient,ReviewClient reviewClient){
        this.jobrepo = repo;
//        this.restTemplate = rt;
        this.companyClient = companyClient;
        this.reviewClient = reviewClient;
    }

    private JobDTO convertToDto(Job j){
//        Company c = restTemplate.getForObject(companyUrl+j.getCompanyID(), Company.class);
//        ResponseEntity<List<Review>> reviewResponse = restTemplate.exchange(reviewUrl + j.getCompanyID(), HttpMethod.GET, null, new ParameterizedTypeReference<List<Review>>() {
//
//        });
//        List<Review> reviews = reviewResponse.getBody();
          Company c =companyClient.getCompany(j.getCompanyID());
          List<Review> reviews = reviewClient.getReviews(j.getCompanyID());

        return JobMapper.mapToJobWithDTO(j,c,reviews);
    }

    @Override
    public List<JobDTO> findAll() {
        List<Job> jobs = jobrepo.findAll();
        List<JobDTO> jobDTOS = new ArrayList<>();

        for(Job j : jobs) {
//            Company c = restTemplate.getForObject(url+j.getCompanyID(), Company.class);
//            System.out.printf(String.valueOf(c));
            jobDTOS.add(convertToDto(j));
        }

        return jobDTOS;
    }

    @Override
    public JobDTO getJobById(Long Id) {
        Job j = jobrepo.findById(Id).orElse(null);
//        Company c = restTemplate.getForObject(url+j.getCompanyID(), Company.class);

        return convertToDto(j);
    }

    @Override
    public void createJob(Job job) {
        jobrepo.save(job);
    }

    @Override
    public boolean deleteJobById(Long id) {
        try{
            jobrepo.deleteById(id);
            return  true;
        }catch (Exception e){
            return false;
        }
    }

    @Override
    public boolean updateJob(Long id, Job job) {
        Optional<Job> jobOpt = jobrepo.findById(id);
        if(jobOpt.isPresent()){
            Job ujob = jobOpt.get();
            ujob.setTitle(job.getTitle());
            ujob.setDescription(job.getDescription());
            ujob.setMinSalary(job.getMinSalary());
            ujob.setMaxSalary(job.getMaxSalary());
            ujob.setLocation(job.getLocation());
            jobrepo.save(ujob);
            return true;
        }
        return  false;
    }
}
