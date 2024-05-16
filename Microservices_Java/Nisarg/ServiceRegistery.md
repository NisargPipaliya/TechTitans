# ServiceRegistry
- It is used in microservice architecture to enable dynamic service discovery.
- Every microservice register itself with service registry and it enable us to discover microservice dynamically.
- If one service wants to communicate with other, then it needs to go to S.R. to get the location of desired service and then communication begins.
- And when a M.S. shutdowns, S.R. Automatically de-registers it.
![alt text](image-3.png)

<br/>

---
# Why using service registry is beneficial?
- Dynamic Service discovery (No HardCoded URLs)
    - If using hardcoded url, so when service is relocated, then it's IP will change, URL will change, so we need to make changes everywhere, where we have used hardcoded urls.
- Load Balancing
    - Service registry can help in L.B. by distributing incoming traffic to multiple instances of a single service.
- Fault Tolerance and resilience
    - If a service fails, and other services are not aware that a service has failed, and when trying to communicate with it, there will be **ERRORS** everywhere.
    - But when using S.R. it will make sure to mark the failed services so that other active service are aware of it, so that this active service can transfer their request to healthy instances of that service.
- Scalability and Elasticity
    - S.R. provides centralized mechanism to manage service endpoints, so it is easy to scale up or down.
- Service Monitoring and Health checks

---
# Spring Cloud Eureka
- It is a service registry.
- It has two parts:
    - Server: registers service.
    - Client: discovers service.
```xml
<!-- Server dependency -->
   <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-netflix-eureka-server</artifactId>
    </dependency>

<!-- Client Dependency -->

<!-- Add this in properties, at starting of the file -->
<spring-cloud.version>2023.0.1</spring-cloud.version>

<dependency>
			<groupId>org.springframework.cloud</groupId>
			<artifactId>spring-cloud-starter-netflix-eureka-client</artifactId>
			<version>4.1.1</version>
</dependency>
<!-- Add this before Build tag, and after dependencies tag -->
	<dependencyManagement>
		<dependencies>
			<dependency>
				<groupId>org.springframework.cloud</groupId>
				<artifactId>spring-cloud-dependencies</artifactId>
				<version>${spring-cloud.version}</version>
				<type>pom</type>
				<scope>import</scope>
			</dependency>
		</dependencies>
	</dependencyManagement>
```