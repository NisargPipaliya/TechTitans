# OpenFiegn
- Feign is a declarative web service client designed to make writing HTTP clients easier.
- Till now we used **RestTemplate**, but there we need to write boiler-plate code again and again.
- It provides us simple functions to interact with other services.
```java
Company c = companyClient.getCompany(jobObj);
```

- Advantage:
    - Easy to use
    - Integration with eureka
    - Built in load balancing with Ribbon
    - Support Fallbacks and Circuit Breakers

---

# OpenFeign Config
- Add **@EnableFeignClients** Annotation in our main class of our application (class where @SpringBootApplication is used.)
- Then create interface for the service that we want to access as:
```java
@FeignClient(name="CompanyMS")
public interface CompanyClient {
    @GetMapping("/companies/{id}")
    public Company getCompany(@PathVariable("id") Long id);
}
```