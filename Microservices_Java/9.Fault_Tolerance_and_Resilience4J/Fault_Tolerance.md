# Fault Tolerance
- Ability to continue operating without interruption.
- For Example: 
    Among Multiple Microservices of our app, if one fails, then all the calls going to that microservice will fail, and whole app/network of services will fail.
- Resilience: Ability to recover quickly from difficulties.

## Need of Fault Tolerance
- Fault Isolation
- Network Latency
- Deployment Issues
- Increased Complexity
- Elasticity
- Tolerating External Failure

## Techniques for Resilience
- Retries
- Rate Limiting
- Bulkheads : A pattern, about isolating different parts of system to prevent failure propagation, by dedicating separate instance.
- Circuit Breakers: A circuit breaker in microservices is a design pattern that acts as a protective shield to ensure a system remains operational, even when some parts are experiencing issues. It works similarly to an electrical circuit breaker by stopping the flow of requests to a service that appears to be failing.
- Fallbacks: Alternative actions or responses that are provided when a microservice is unavailable or fails to provide response.
    - They are pre-defined.
- Timeouts: Time for which a client waits until it gets response from microservice.
- Graceful Degradation: Ability of microservice to continue functioning with reduced functionality when facing issues of high load, so at that time, some non-essential services are stopped so that only essential services keep working.
    - It helps prevent failure in case of high load 

### For implementing all the above features we use Resilience4j library
### Alternatives
- Sentinel
- Reverence4j
- Hystrix
- Spring Cloud Circuit Breaker
- Akka
- Spring Retry

<br><br>

---

# Resilience4J
- Lightweight easy to use fault tolerance library
- Easy integration with spring boot
- Functional programming paradigms
- [Docs](https://resilience4j.readme.io/docs/getting-started)


## Modules in Resilience4J
- Retry module
    - It's uncommon for network call or method invocation to fail temporarily
    - We might retry the operation before giving up
    - Retry module enables to easily implement retry logic in our app.
- RateLimiter
    - We might have a service which can handle only certain number of requests in given time.
    - RateLimiter module allows us to enforce restrictions and protect our services from too many requests.
- Bulkhead
    - Isolates Failures and prevent them from cascading through the system.
    - Limit the amount of parallel executions or concurrent calls to prevent system resources from being exhausted.
- CircuitBreaker
    - Used to prevent a network or service failure from cascading to other services.
    - Circuit breaker 'Trips' or opens and prevent further call to that service.

---
## Rate Limiting
- A Technique for limiting network traffic.
- Importance:
    - Prevent Abuse
    - Resource Allocation
    - Cost Management is app is deployed on cloud.
- Use Cases:
    - APIs
    - Web Scrapping
    - Prevent Brute force login attacks
    - Avoid DoS/DDoS
