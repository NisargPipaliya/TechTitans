# Kubernetes Services
---

### What is service and when we need it?
- Each Pod has it's own IP
- And pods are ephemeral - i.e. destroyed frequently.
- And when it is recreated it gets new IP.
- So we cannot use ```POD IP``` to refer a pod.
- ##### With service we have a stable IP to access to a pod.
- it is also used to load balancing.
- Loose coupling for communication with and within cluster.
- A service identifies pods via selectors( Key value pair)
    - Selectors are nothing but labels in metadata of pod/deployment.
    - Which port in a pod, we need to forward the request to?
        - We can know this by Target Port.
        - Port is arbitrary.
        - Target Port is port where container is listening.

---

### Types of services
- ClusterIP 
    - Default Type of service
- Headless 
    - If client want to communicate with 1 pod directly
    - or Pods want to talk directly to specific pod
        - Eg: Stateful apps like DB, where worker needs to synch data from master.
    - So client needs to figure out IP od each Pod.
    ```yaml
    spec: 
      clusterIP: None 
    ```
    - We have it along with ClusterIP Service

- NodePort
    - Extension of ClusterIP.
    - Creates service that is accessible on static port on each worker node of cluster.
    - External traffic can access this directly, i.e. no need for ingress.
    - Port Range: ```30,000 - 32,767```
    - ```Not efficient and Not secure```

- LoadBalancer 
    - Extension of NodePort.
    - Service is accessible externally using cloud providers LoadBalancer.
    - When we create this service, ClusterIP and NodePort service is created by default.
        - But here in NodePort, it is not directly accessible, but only through LoadBalancer.
