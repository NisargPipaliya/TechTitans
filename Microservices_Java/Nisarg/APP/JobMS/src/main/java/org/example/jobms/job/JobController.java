package org.example.jobms.job;

import org.example.jobms.job.dto.JobWithCompanyDTO;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("/jobs")
public class JobController {
        private final JobService jobService;
        JobController(JobService jobService){
            this.jobService = jobService;
        }

        @GetMapping
        public ResponseEntity<List<JobWithCompanyDTO>> findAll(){
            return ResponseEntity.ok(jobService.findAll());
        }

        @PostMapping
        public ResponseEntity<String> createJob(@RequestBody Job job){
            jobService.createJob(job);
            return new ResponseEntity<>("Job Added Successfully", HttpStatus.CREATED);
        }

        @GetMapping("/{id}")
        public ResponseEntity<Job> getJobById(@PathVariable Long id){
         Job job = jobService.getJobById(id);
         if(job == null)
             return new ResponseEntity<>(HttpStatus.NOT_FOUND);
         return new ResponseEntity<>(job,HttpStatus.OK);
        }

        @DeleteMapping("/{id}")
        public ResponseEntity<String> deleteJob(@PathVariable Long id){
            boolean deleted = jobService.deleteJobById(id);
            if(deleted)
                return new ResponseEntity<>("Job Deleted",HttpStatus.OK);
            return new ResponseEntity<>(HttpStatus.NOT_FOUND);
        }

        @PatchMapping("/{id}")
    public ResponseEntity<String> updateJob(@PathVariable Long id, @RequestBody Job updatedjob){
            boolean updated = jobService.updateJob(id,updatedjob);
            if(updated)
                return new ResponseEntity<>("Job Updated Successfully",HttpStatus.OK);
            return  new ResponseEntity<>(HttpStatus.NOT_FOUND);
        }


}
