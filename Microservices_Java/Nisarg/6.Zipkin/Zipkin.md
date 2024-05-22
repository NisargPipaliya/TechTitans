# Distributed Tracing
- In microservice, it is difficult to track a request, that from where it came and where it goes, as in microservice, all the service won't be written in same language and also the DB are not same.
- So to Track this request, when something goes wrong or request becomes slower, so for this we use **Distributed Tracing**.
- *Distributed Tracing enables you to trace your request from start to end*
- It help us to solve:
    - Request Visualization
    - Identify Performance Bottleneck
    - Error Analysis and Debugging
    - Tracking Dependency
    - Performance Optimization
        - Used for capacity planning

### Tools for Distributed tracing
- [Article](https://medium.com/cloud-native-daily/7-best-tracing-tools-for-microservices-27a5e3bc4b9c)
- Helios
- DataDog
- HoneyComb
- Jaeger
- Zipkin
- New Relic
- Splunk

### Architecture of Distributed Tracing System
![alt text](image.png)

---

# Zipkin
- A tool for Distributed Tracing.
- Open-source distributed tracing system.
- Trace: description of transaction, or journey of a request in entire app.
    - Represented by Trace ID.
- Span: Journey of request in a single service.
    - Represented by Span ID.
- Run Zipkin locally by ```docker run -d -p 9411:9411 openzipkin/zipkin```

---

# Micrometer
- Micrometer provides insights that help you keep tabs on your application's performance.
- Helps you collect metrics from your application
- Acts as a middleman or a bridge between your application and the metrics collection systems
- It offers a vendor-neutral interface
- You can abstract away the complexities of interacting with different metrics collection systems
- It simplifies process of collecting metrics from your app.

