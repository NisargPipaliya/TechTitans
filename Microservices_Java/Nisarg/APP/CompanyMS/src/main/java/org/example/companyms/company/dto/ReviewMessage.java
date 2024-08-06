package org.example.companyms.company.dto;

import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

@Getter @Setter @ToString
public class ReviewMessage {
    private long id;
    private String title;
    private String description;
    private Double rating;
    private long companyId;
}
