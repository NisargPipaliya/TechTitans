package org.example.jobms.job.clients;

import org.example.jobms.job.external.Company;
import org.springframework.cloud.openfeign.FeignClient;
import org.springframework.stereotype.Component;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;


@FeignClient(name="CompanyMS")
public interface CompanyClient {
    @GetMapping("/companies/{id}")
    public Company getCompany(@PathVariable("id") Long id);
}
