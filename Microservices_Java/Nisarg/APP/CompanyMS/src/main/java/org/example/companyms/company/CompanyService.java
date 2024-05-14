package org.example.companyms.company;

import java.util.List;

public interface CompanyService {
    void createCompany(Company company);
    List<Company> getAllCompanies();
    Company getCompanyById(Long id);
    boolean updateCompany(Company company, Long id);
    boolean deleteCompany(Long id);
}
