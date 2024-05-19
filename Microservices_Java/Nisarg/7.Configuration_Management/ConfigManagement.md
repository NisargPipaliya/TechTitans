# Configuration Management
- Simply means managing and controlling the configurations of each microservice in the system
- Configuration may include details such as database connections, external service URLs, caching settings, and more
- *Challenge*: As the number of Microservices increases in your architecture, managing the individual configurations can become a complex task.
- A centralized Config Server provides a central place for managing configurations across all microservices
- It simplifies configuration management and increases operational efficiency.

### Features
- Centralized and Versioned Config
- Dynamic Updates
- Security
- Application and Profile Specific Config
- Single Source of truth
- Easier to manage and update config
- Enhances Security and control
- Easy to deploy and scale Microservices

---

# Spring Cloud Config Server
- Spring Cloud Config Server is part of the Spring Cloud project, a suite of tools specifically designed for building and managing cloud-native applications.
![alt text](image.png)

### Benefits
- Storing and Serving Configurations
- Refreshing Configurations
- Easy Integration with spring boot
- Support Different Env

## Configuration for Config Server
```xml
<dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-actuator</artifactId>
        </dependency>
        <dependency>
            <groupId>io.micrometer</groupId>
            <artifactId>micrometer-tracing-bridge-brave</artifactId>
        </dependency>
        <dependency>
            <groupId>io.zipkin.reporter2</groupId>
            <artifactId>zipkin-reporter-brave</artifactId>
        </dependency>
        <dependency>
            <groupId>io.github.openfeign</groupId>
            <artifactId>feign-micrometer</artifactId>
        </dependency>
        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-config-server</artifactId>
        </dependency>
        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-netflix-eureka-client</artifactId>
        </dependency>
```

- Now create a **public github repo**, and create application.properties or application.yml file in it.
- Then copy link from **```Code Button```**  with _.git_ extension.
- And then paste this link in application.properties file of config server.
```yml
spring.application.name=ConfigServer
server.port=8606

# Eureka
eureka.client.serviceUrl.defaultZone=http://localhost:8761/eureka/

# Zipkin
management.tracing.sampling.probability=1.0

# Config server
spring.cloud.config.server.git.uri=https://github.com/NisargPipaliya/1_MS_Config_Server.git
spring.cloud.config.server.git.clone-on-start=true
```

--- 

# Client Side
- Dependency
```xml
<dependency>
			<groupId>org.springframework.cloud</groupId>
			<artifactId>spring-cloud-starter-config</artifactId>
</dependency>
```

- Properties file
```yml
spring.config.import=configserver:http://localhost:8606

spring.config.import=optional:configserver:http://localhost:8606 # We add optional to above import, so that even if config server is down, we will start our app with local application.properties file that is in our app.

spring.profiles.active=dev # It is written to select single application.properties file from multiple files.
# we can make multiple files as application-dev.properties
# application-prod.properties
# Anything after '-' is known as profile.
# and we can set active profile, which will select which file to use.
```
