## Create Docker Image
- I have created a docker image of a react app, and i will be using it here.
- docker build -t todocontext:1.0 .


## Now Load this Image in minikube
```bash
minikube docker-env # run the last command that is shown.
# By this we are moving our docker deamon from our system to minikube

minikube image load todocontext:1.0

minikube image ls --format table # list all images in minikube
```

## To Create Pod
-  ```bash  kubectl run pod-name --image=todocontext:1.0 --image-pull-policy=Never --restart=Never```
- It created pod for the image, but we can't access the app as we have not created external service for the given pod.
- So we will create a deployment and external service through which we can access the app.

## Deployment and Service

```yaml
apiVersion: v1
kind: Service
metadata:
  name: local
spec:
  selector:
    app: local
  type: LoadBalancer   # Specifies External Service
  ports:
  - protocol: TCP
    port: 5173        # It means internally where the service will be available.
    targetPort: 5173  # It means to which port the request will be forwarded internally.
    nodePort: 30000   # Port on which this external service is available.
                      # Range 30,000 - 32,767
    # nodePort forward request to port, then port forward it to targetPort, where our react app is running.
---
apiVersion: apps/v1
kind: Deployment
metadata:
  name: local-depl
  labels:
    app: local
spec:
  replicas: 1
  selector:
    matchLabels:
      app: local
  template:
    metadata:
      labels:
        app: local
    spec:
      containers:
      - name: toctx
        image: todocontext:1.0
        ports:
          - containerPort: 5173
```

-  ```bash kubectl apply -f local.yaml ```

- Now to access the service, 
```bash
minikube service local # local is service name.
```
- It will open browser on port 30000 and we can see our app there.


# At End of this, close the powershell to bring back docker deamon from minikube to our system