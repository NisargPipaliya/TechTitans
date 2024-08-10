package org.example.jobms.job;

import org.springframework.data.jpa.repository.JpaRepository;

public interface JobRepo extends JpaRepository<Job,Long> {
}
