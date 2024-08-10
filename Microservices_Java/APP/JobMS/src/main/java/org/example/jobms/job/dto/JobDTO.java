package org.example.jobms.job.dto;

import lombok.Getter;
import lombok.Setter;
import lombok.ToString;
import org.example.jobms.job.external.Company;
import org.example.jobms.job.external.Review;

import java.util.List;

@Getter @Setter @ToString
public class JobDTO {
    private Long jobId;
    private String jobTitle;
    private String jobDescription;
    private String maxSalary;
    private String minSalary;
    private String jobLocation;
    private Company company;
    private List<Review> reviews;

}
