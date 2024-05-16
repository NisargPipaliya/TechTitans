package org.example.jobms.job.dto;

import lombok.Getter;
import lombok.Setter;
import org.example.jobms.job.Job;
import org.example.jobms.job.external.Company;

@Getter @Setter
public class JobWithCompanyDTO {
    private Job job;
    private Company company;

}
