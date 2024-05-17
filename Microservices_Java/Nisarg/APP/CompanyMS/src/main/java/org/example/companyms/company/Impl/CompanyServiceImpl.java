package org.example.companyms.company.Impl;

import org.example.companyms.company.Company;
import org.example.companyms.company.CompanyRepo;
import org.example.companyms.company.CompanyService;
import org.springframework.stereotype.Service;

import java.util.List;
@Service
public class CompanyServiceImpl implements CompanyService {
    CompanyRepo companyRepo;
    CompanyServiceImpl(CompanyRepo repo){
        companyRepo = repo;
    }

    @Override
    public void createCompany(Company company) {
        companyRepo.save(company);
    }

    @Override
    public List<Company> getAllCompanies() {
        return companyRepo.findAll();
    }

    @Override
    public Company getCompanyById(Long id) {
        return companyRepo.findById(id).orElse(null);
    }

    @Override
    public boolean updateCompany(Company company, Long id) {
        Company c = companyRepo.findById(id).orElse(null);
        if(c != null){
            companyRepo.save(company);
            return true;
        }
        return false;
    }

    @Override
    public boolean deleteCompany(Long id) {
        try{
            companyRepo.deleteById(id);
            return true;
        }
        catch (Exception e){
            return false;
        }
    }
}
