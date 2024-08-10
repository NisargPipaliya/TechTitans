package org.example.reviewms.review.Impl;

import org.example.reviewms.review.Review;
import org.example.reviewms.review.ReviewRepo;
import org.example.reviewms.review.ReviewService;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class ReviewServiceImpl implements ReviewService {
    private ReviewRepo reviewRepo;

    ReviewServiceImpl(ReviewRepo reviewRepo){
        this.reviewRepo = reviewRepo;
    }
    @Override
    public boolean addReview(Long companyId, Review review) {

        if(companyId == null || review == null)
            return false;
        review.setCompanyID(companyId);
        reviewRepo.save(review);
        return true;
    }

    @Override
    public List<Review> getAllReviews(Long companyId) {
        return reviewRepo.findByCompanyID(companyId);
    }

    @Override
    public Review getReviewById(Long reviewId) {
        Review review = reviewRepo.findById(reviewId).orElse(null);
        return review;
    }

    @Override
    public boolean updateReview(Long reviewId, Review updatedReview) {
        Review review = reviewRepo.findById(reviewId).orElse(null);
        if(review != null) {
            review.setTitle(updatedReview.getTitle());
            review.setDescription(updatedReview.getDescription());
            review.setCompanyID(updatedReview.getCompanyID());
            review.setRating(updatedReview.getRating());
            reviewRepo.save(review);
            return true;
        }
        return false;

    }

    @Override
    public boolean deleteReview(Long reviewId) {
        Review r = reviewRepo.findById(reviewId).orElse(null);
        if(r != null){
            reviewRepo.deleteById(reviewId);
            return  true;
        }
        return false;
    }
}
