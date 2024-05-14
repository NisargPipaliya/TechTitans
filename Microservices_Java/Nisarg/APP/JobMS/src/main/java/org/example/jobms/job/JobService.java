package org.example.jobms.job;

import java.util.List;

public interface JobService {
    List<Job> findAll();
    Job getJobById(Long Id);
    void createJob(Job job);
    boolean deleteJobById(Long id);
    boolean updateJob(Long id, Job job);
}
