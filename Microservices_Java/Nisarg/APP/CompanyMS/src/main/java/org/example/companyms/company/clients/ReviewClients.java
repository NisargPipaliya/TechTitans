package org.example.companyms.company.clients;

import org.springframework.cloud.openfeign.FeignClient;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;

@FeignClient("REVIEWMS")
public interface ReviewClients {
    @GetMapping("/reviews/averageRating")
    Double getAverageRating(@RequestParam("companyId") Long companyId);
}
