package org.example.jobms.job.mapper;

import org.example.jobms.job.Job;
import org.example.jobms.job.dto.JobDTO;
import org.example.jobms.job.external.Company;
import org.example.jobms.job.external.Review;

import java.util.List;

public class JobMapper {

    public static JobDTO mapToJobWithDTO(Job j, Company c, List<Review> r){
        JobDTO obj = new JobDTO();
        obj.setJobId(j.getId());
        obj.setJobTitle(j.getTitle());
        obj.setJobDescription(j.getDescription());
        obj.setJobLocation(j.getLocation());
        obj.setMaxSalary(j.getMaxSalary());
        obj.setMinSalary(j.getMinSalary());
        obj.setCompany(c);
        obj.setReviews(r);
        return obj;
    }
}
