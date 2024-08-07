package org.example.jobms.job.external;

import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

@Getter @Setter @ToString
public class Review {
    private Long id;
    private String title;
    private String description;
    private double rating;
}
