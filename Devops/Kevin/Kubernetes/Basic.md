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

### Information of all components
```
kubectl get all
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

### Assign external ip address to service
- It will open the browser with external ip address 
```
minikube service <service name>
```

## Debugging

### Printing the logs

```
kubectl logs <pod name>
```

### Extra information
- It will describe pod info like what is happening while creating pods
```
kubectl describe pod <pod name>

kubectl describe service <service name>
```
### Starting interactive terminal
- If already created with same cofiguration fle then insted of creating new one it is going to update the existing one.
```
kubectl exec -it <pod name> -- bin/bash
```

### Convert plaintext to base64

```
echo -n 'Hello' | sbase64
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

## Sample configuration file for secreat

```
apiVersion: v1
kind: Secret
metadata:
  name: mongodb-secret
type: Opaque
data:
  mongo-root-username: SGVsbG8=
  mongo-root-password: SGVsbG8=

<!-- Use of it-->
    env:
    - name: MONGO_INITDB_ROOT_USERNAME
      valueFrom:
        secretKeyRef:
          name: mongodb-secret
          key: mongo-root-username
```

## Sample configuration file for configmap

```
apiVersion: v1
kind: ConfigMap
metadata:
  name: mongo-config
data:
  database_url: mongodb-service


<!-- Use of it -->
    env:
    - name: ME_CONFIG_MONGODB_SERVER
      valueFrom:
        configMapKeyRef:
          name: mongo-config
          key: database_url

```


# Ingress
```
minikube start
```
```
minikube addons enable ingress
```
```
minikube addons enable ingress-dns
```

### Wait until you see the ingress-nginx-controller-XXXX is up and running using Kubectl 
```
get pods -n ingress-nginx
```


### Create an ingress using the K8s example yaml file

```
apiVersion: networking.k8s.io/v1
kind: Ingress
metadata:
  name: dashboard-ingress
  namespace: kubernetes-dashboard
spec:
  rules: 
  - host: dashboard.com
    http: 
      paths:
      - pathType: Prefix
        path: "/"
        backend:
          service:
            name: kubernetes-dashboard
            port:
              number: 80 
```

### Update the service section to point to the NodePort Service that you already created
- For windows path of host file should be 'C:\Windows\System32\drivers\etc\hosts'
- Append 127.0.0.1 hello-world.info to your /etc/hosts file on MacOS (NOTE: Do NOT use the Minikube IP)

### Run below cmmand ( Keep the window open. After you entered the password there will be no more messages, and the cursor just blinks)
```
minikube tunnel
```

- Hit the hello-world.info ( or whatever host you configured in the yaml file) in a browser and it should work

----
# Container Communicatuion

  - Every pod has a unique IP address
  - Pod is a isolated virtual host.
  - containers inside one pod can talk to each other via localhost and port number.

----
# Volumes

### requirements
  - Storage doesn't depend on the pod lifecycle.
  - It must be available on all nodes.
  - it needs to survive even if cluster crashes.

#### types of volumes
  - Persistance volume
    - a clusture resource
    - created via YAML file.
    - needs actual physical storage.
    - depending on storage type spec. attr. are differs.
    - it are not namespaced.
  
  - Local volume
    - not being tied to one specific node
    - not surviving in cluster crashes
    - rest all the reqs are satisfied of persistance volume

#### ''Persistance Volume Claim(PVC)'' for use the volume in pods.
- claim must exist in the same namespace as pod.


#### ConfigMap & Secret

#### Storage Class(SC)
- It is another abstraction layer upon the PVC.
  - A pod claims for storage via PVC
  - PVC request storage from SC
  - SC creates PV(Physical Volume) that meets the need of claim.

### [Sample Project Click here](./Mosquitto)