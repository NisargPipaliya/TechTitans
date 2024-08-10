### Resilance4J
---
#### Dependancy
```
<!-- https://mvnrepository.com/artifact/org.springframework.cloud/spring-cloud-starter-circuitbreaker-resilience4j -->
<dependency>
    <groupId>org.springframework.cloud</groupId>
    <artifactId>spring-cloud-starter-circuitbreaker-resilience4j</artifactId>
    <version>3.1.1</version>
</dependency>

<dependency>
			<groupId>org.springframework.boot</groupId>
			<artifactId>spring-boot-starter-actuator</artifactId>
</dependency>

```

#### Applicaion.properties
```
# Actuator
management.health.circuitbreakers.enabled=true
management.endpoints.web.exposure.include=health
management.endpoint.health.show-details=always

# resilience4j
resilience4j.circuitbreaker.instances.companyBreaker.register-health-indicator=true
resilience4j.circuitbreaker.instances.companyBreaker.sliding-window-size=10
resilience4j.circuitbreaker.instances.companyBreaker.minimum-number-of-calls=5
resilience4j.circuitbreaker.instances.companyBreaker.permitted-number-of-calls-in-half-open-state=3
resilience4j.circuitbreaker.instances.companyBreaker.wait-duration-in-open-state=10s
resilience4j.circuitbreaker.instances.companyBreaker.failure-rate-threshold=50
resilience4j.circuitbreaker.instances.companyBreaker.automatic-transition-from-open-to-half-open-enabled=
resilience4j.circuitbreaker.instances.companyBreaker.sliding-window-type=count_based
#For retry
resilience4j.retry.instances.companyBreaker.max-attempts=5
resilience4j.retry.instances.companyBreaker.wait-duration=2s
# For Rate Limitor
resilience4j.ratelimiter.instances.companyBreaker.timeout-duration=0
resilience4j.ratelimiter.instances.companyBreaker.limit-refresh-period=4
resilience4j.ratelimiter.instances.companyBreaker.limit-for-period=2


```

#### Update in implemantation class

```
@Override
    // @CircuitBreaker(name = "companyBreaker", fallbackMethod = "companyBreakerFallback")
    @Retry(name = "companyBreaker", fallbackMethod = "companyBreakerFallback")
    public List<JobDTO> findAll() {
        List<Job> jobs =  jobRepository.findAll();
        List<JobDTO> jobDTOS = new ArrayList<>();

        return jobs
                .stream()
                .map(this::convertJobDTO)
                .collect(Collectors.toList());
    }
    

    // user can't see any errors insted see the returned value of fallback
    public List<String> companyBreakerFallback(Exception e) {
        List<String> companyBreakers = new ArrayList<>();
        companyBreakers.add("dummy");
        return companyBreakers;
    }

```