# Basic Commands & details of  K8s
----------------------------
-----------------------
## Layers
    Deployment :- Manges Replicaset
    Replicas :- manages pods
    Pod :- it is a container
    Container :- it is managed by K8s


### Set docker as default context ;'
```
docker context use default
```

### starting the minicube 
- Ensure that docker deamon is running before excuting the command
- if any error occur then try to remuve config file at location "C:\Users\user\\.kube"

```
minikube start --driver=docker
```


### Information of running nodes
```
kubectl get nodes
```
### Information of running pods
```
kubectl get pod

<!-- For More info of pods -->
kubectl get pod -o wide
```

### Information of Services
```
kubectl get services
```

### Information of deployments
```
kubectl get deployments
```

### information / Status of perticular deployment
```
kubectl get deployment <deployment name> -o yaml

<!-- For storing the reasult in file -->
kubectl get deployment <deployment name> -o yaml > <file name> 
```


### Creating pods / deployment

#### Direct by cmd
- Pod is smallesst unit, but we are creating <mark>Deployments</mark> which is an abstraction over pods
- Deployment has blueprinyt for creating pods
```
kubectl create deployment <deployment name> --image=<image name>
```
#### By yaml file

```
kubectl apply -f <file.yaml>
```


### Deletethe deployment
- It will delete the deployment which <mark>autmatically delets the replica and pods asssociated with it.
```
kubectl delete <deployment name>

kubectl delete -f <file name by which it is created>
```

### Information of replicas
- It is <mark>automatically managed</mark> by K8s deployments
- It is a layer between deployments and pods.

```
kubectl get replicaset
```

###  Edit the deployment
- It will open configuration file of deployment so that we can edit it and when save it, it  creats a new replica which terminates the currently running pod and start a new pod as per configuration (All the things are done automatically)
```
kubectl edit deployment <deployment name>
```

## Debugging

### Printing the logs

```
kubectl logs <pod name>
```

### Extra informatio about a pod
- It will describe pod info like what is happening while creating pods
```
kubectl describe pod <pod name>
```
### Starting interactive terminal
- If already created with same cofiguration fle then insted of creating new one it is going to update the existing one.
```
kubectl exec -it <pod name> -- bin/bash
```



## sample Configuration file for Deployment

```
apiVersion: apps/v1
kind: Deployment
metadata:
  name: nginx-deployment
  # labels for the deployment
  labels:
    app: nginx
# spec of the deployment
spec:
  replicas: 3
  # selector of the deployment(same as the label of the pods)
  selector:
    matchLabels:
      app: nginx
  # template of the creating pods
  template:
  # metadata of the pods(same as the label of the deployment)
    metadata:
      labels:
        app: nginx
    # spec of the containers
    spec:
      containers:
      - name: nginx
        image: nginx
        ports:
        - containerPort: 80
```


## Sample configuration file for services

```
apiVersion: v1
kind: Service
# metadata of the service
metadata:
  name: nginx-service
# spec of the service
spec:
  # selector of the service(same as the label of the deployment)
  selector:
    app: nginx
  # ports of the service 
  ports:
    - protocol: TCP
      port: 80
      targetPort: 80
```