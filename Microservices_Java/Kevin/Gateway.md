###     Create a Spring Boot Project with given dependancy
- zipkin
- eureka client
- cloud gateway

### Update porperties as given 

```
spring.application.name=gateway
server.port=8085



# Eureca client
#eureka.client.register-with-eureka=true
#eureka.client.fetch-registry=true

#Zipkin
management.tracing.sampling.probability=1.0


# Config server
spring.config.import=optional:configserver:http://localhost:8084
spring.profiles.active=dev

# Gateway

spring.cloud.gateway.mvc.routes[0].id=company-service
spring.cloud.gateway.mvc.routes[0].uri=http://localhost:8081
spring.cloud.gateway.mvc.routes[0].predicates[0]=Path=/companies/**

spring.cloud.gateway.mvc.routes[1].id=jon-service
spring.cloud.gateway.mvc.routes[1].uri=http://localhost:8082
spring.cloud.gateway.mvc.routes[1].predicates[0]=Path=/jobs/**

spring.cloud.gateway.mvc.routes[2].id=review-service
spring.cloud.gateway.mvc.routes[2].uri=http://localhost:8083
spring.cloud.gateway.mvc.routes[2].predicates[0]=Path=/reviews/**

# Logging level of application
logging.level.root=info
logging.level.org.springframework.cloud.gateway = TRACE
logging.level.org.springframework.cloud.gateway.route.RouteDefinitionLocator=INFO
```