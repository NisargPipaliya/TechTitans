### Create A new Maven Sprigboot project

#### dependancy :-
- config server
-eureka discovery client

#### Add annotation to main class

```
package org.example.configserver;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.config.server.EnableConfigServer;

@SpringBootApplication
@EnableConfigServer
public class ConfigserverApplication {

    public static void main(String[] args) {
        SpringApplication.run(ConfigserverApplication.class, args);
    }

}

```

### Application.properties

```
spring.application.name=config-server
server.port=8084

# Eureca client
eureka.client.service-url.defaultZone=http://localhost:8761/eureka/

spring.cloud.config.server.git.uri=https://github.com/Kevin0403/applicatinon-config
```

---

### Dependancy in microservices to fetch the properties
- Spring Cloud Config Client

#### Changes in their properties

```
# Config server
spring.config.import=configserver:http://localhost:8084
spring.profiles.active=default
```
 
 If we want to make our configserver optional (If cnfig server is down then skip it)

```
# Config server
spring.config.import=optional:configserver:http://localhost:8084
spring.profiles.active=dev
```