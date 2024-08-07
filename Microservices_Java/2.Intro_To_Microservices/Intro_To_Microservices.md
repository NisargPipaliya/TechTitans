# Monolithic
- Everything is unified.
- Monolithic architecture is a design where all the components of an application are interconnected and interdependent.
- Monolithic app arch:
![alt text](image.png)

---

# Problems with Monolithic Arch.
→ Difficult to Implement Changes
→ Lack of Scalability
→ Long-term Commitment to a Single Technology Stack
→ Application Complexity and Its Effect on Development and Deployment
→ Slowing Down of IDEs
→ Increased Application Start Time
→ Large Project Size
→ Deploying for Small Changes
→ Team Collaboration and Autonomy

---

# What Are Microservices?
- Microservices structures an application as a collection of small autonomous services.
- It works by breaking down app in small services.
- And this services communicates with each other by protocols like http etc.
- Microservice App Arch:
![alt text](image-1.png)

# Principles of Microservices
- Single Responsibility: Each service should be responsible for only one task.
- Independence: Each service should be independent of each other.
- Decentralization: Each service manages it's on DB, CodeBase and things.
- Failure Isolation: Failing of one service dosen't mean that whole app will be down.
- CI/CD: Continuous Integration and Delivery.


---

# Problems Solved by Microservices
- Scalability: Scale-up/down
- Flexibility: In tech stack, updation etc.
- Simplicity