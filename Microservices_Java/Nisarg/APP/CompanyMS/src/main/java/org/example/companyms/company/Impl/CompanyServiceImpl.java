package org.example.companyms.company.Impl;

import org.example.companyms.company.Company;
import org.example.companyms.company.CompanyRepo;
import org.example.companyms.company.CompanyService;
import org.example.companyms.company.clients.ReviewClients;
import org.example.companyms.company.dto.ReviewMessage;
import org.springframework.stereotype.Service;

import java.util.List;
@Service
public class CompanyServiceImpl implements CompanyService {
    CompanyRepo companyRepo;
    private final ReviewClients reviewClients;
    CompanyServiceImpl(CompanyRepo repo,ReviewClients reviewClients){
        companyRepo = repo;
        this.reviewClients = reviewClients;
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
    public void updateCompany(Company company, Long id) {
        Company c = companyRepo.findById(id).orElse(null);
        if(c != null){
            companyRepo.save(company);
        }
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

    @Override
    public void updateCompanyRating(ReviewMessage message){
        System.out.println(message.getDescription());
        Company c = companyRepo.findById(message.getCompanyId()).orElse(null);
        if(c != null){
            double averageRating = reviewClients.getAverageRating(c.getId());
            c.setRating(averageRating);
            companyRepo.save(c);
        }


    }
}
