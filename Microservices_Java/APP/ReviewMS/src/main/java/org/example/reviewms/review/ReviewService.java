package org.example.reviewms.review;

import java.util.List;

public interface ReviewService {
    boolean addReview(Long companyId,Review review);
    List<Review> getAllReviews(Long companyId);
    Review getReviewById(Long reviewId);
    boolean updateReview(Long reviewId, Review review);
    boolean deleteReview(Long reviewId);
}
