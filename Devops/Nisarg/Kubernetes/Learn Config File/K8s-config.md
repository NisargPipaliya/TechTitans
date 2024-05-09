## Config file
- Each config file has 3 parts.
    - metadata
    - specification
        - It depends on "kind" of config file.
        - kind:deployment
        - kind:service
    - status 
        - automatically generated and updated by kubernetes.
        - kubernetes compares status with specs written in config file.
        - if not same then another replica is created and load is balanced.
        - this is called self healing feature of k8s.
        - From where does k8s gets the status data?
            - From etcd
            - it holds current status of any k8s component.

```yaml
apiVersion: apps/v1
kind: Deployment
metadata: 
  name: deployment-name
  labels:
    app: app-name

spec:
  replicas: 2
  selector: # Used is create connection/communication 
  # For Deployment
    matchLabels:
      app: app-name
  # For Service
    app: app-name
  template:     # It is config for Pod. has it's own metadata and spec section. Blueprint of Pos
    metadata:
      app: app-name
    spec:
      containers:
      - name: docker-image-name
        image: image-name:tag
        ports:
        - containerPort: portNum # Port binding of the container.
        # Used by service to forward requests from other service.

```

## Connecting Components
- Connection is made using Labels, selectors and ports.
- Metadata has labels.
- Specs has selectors.
- In metadata we have key-value pair of component. ( here we have app: name, it can be any).
- Pods get label through template blueprint.
- The label is matched by selector, to create connection.
- Label in deployment is used by "service" selector, to create connection between deployment and service so service can connect with pods.

![alt text](image-3.png)

![alt text](image-2.png)

![alt text](image-4.png)