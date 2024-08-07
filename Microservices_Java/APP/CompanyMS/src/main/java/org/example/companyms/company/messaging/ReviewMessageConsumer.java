package org.example.companyms.company.messaging;

import org.example.companyms.company.CompanyService;
import org.example.companyms.company.dto.ReviewMessage;
import org.springframework.amqp.rabbit.annotation.RabbitListener;
import org.springframework.stereotype.Service;

@Service
public class ReviewMessageConsumer {

    private final CompanyService companyService;

    public ReviewMessageConsumer(CompanyService companyService) {
        this.companyService = companyService;
    }

    @RabbitListener(queues="company_rating")
    public void consume(ReviewMessage message) {
        companyService.updateCompanyRating(message);

    }
}
