package org.example.companyms.company;

import org.example.companyms.company.dto.ReviewMessage;

import java.util.List;

public interface CompanyService {
    void createCompany(Company company);
    List<Company> getAllCompanies();
    Company getCompanyById(Long id);
    void updateCompany(Company company, Long id);
    void updateCompanyRating(ReviewMessage message);
    boolean deleteCompany(Long id);
}
