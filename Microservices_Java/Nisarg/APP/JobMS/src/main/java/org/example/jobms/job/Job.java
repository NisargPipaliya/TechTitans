package org.example.jobms.job;


import jakarta.persistence.*;
import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;


@Entity
@Getter @Setter @AllArgsConstructor @NoArgsConstructor
public class Job {
    @Id
    @GeneratedValue(strategy = GenerationType.SEQUENCE)
    private Long id;
    private String title;
    private String description;
    private String maxSalary;
    private String minSalary;
    private String location;
//    @ManyToOne
//    @Cascade(CascadeType.ALL)
    private Long companyID;
}
