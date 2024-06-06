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


### Delete the deployment
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

---

## Statful Set
- Application that stores the data
- record the state
- eg. Database
- Stateless applications are deployed using the deployment while stateful apps are deployed using the <mark>Statefulset</mark>
- When we crate replicas of statefulset then there will be one slave and remaings are slave. 
  - Only master have access of update the data. Slave can only read the data and it have to stnchronized with the master in order to keep up to date.
  - All the replicas are pointing to different storages.
  - data will be lost when all the podsare die.(so kep try to use persistance storage)
- Every pod in stateful set have unique identifier.
- At the time of creation and deletion of pods orders are maintained.


## Monitoring

- [Prometheus Operator helm chart Repostory](https://github.com/helm/charts/tree/master/stable/prometheus-operator) **Depricated**

- [kube-prometheus-stack](https://github.com/prometheus-community/helm-charts/tree/main/charts/kube-prometheus-stack) Currently managed
 
### Helm Command for installing the helm chart

```
helm install [RELEASE_NAME] prometheus-community/kube-prometheus-stack
```
```
NAME                                                         READY   STATUS    RESTARTS   AGE
pod/alertmanager-prometheus-kube-prometheus-alertmanager-0   2/2     Running   0          2m54s
pod/prometheus-grafana-6597bd8c5f-btsng                      3/3     Running   0          3m29s
pod/prometheus-kube-prometheus-operator-7d798c4898-27v4j     1/1     Running   0          3m29s
pod/prometheus-kube-state-metrics-599c6b59fb-zhs9v           1/1     Running   0          3m29s
pod/prometheus-prometheus-kube-prometheus-prometheus-0       2/2     Running   0          2m53s
pod/prometheus-prometheus-node-exporter-244dg                1/1     Running   0          3m29s

NAME                                              TYPE        CLUSTER-IP       EXTERNAL-IP   PORT(S)                      AGE
service/alertmanager-operated                     ClusterIP   None             <none>        9093/TCP,9094/TCP,9094/UDP   2m54s
service/kubernetes                                ClusterIP   10.96.0.1        <none>        443/TCP                      23m
service/prometheus-grafana                        ClusterIP   10.97.229.114    <none>        80/TCP                       3m30s
service/prometheus-kube-prometheus-alertmanager   ClusterIP   10.111.58.10     <none>        9093/TCP,8080/TCP            3m30s
service/prometheus-kube-prometheus-operator       ClusterIP   10.103.143.124   <none>        443/TCP                      3m30s
service/prometheus-kube-prometheus-prometheus     ClusterIP   10.97.249.238    <none>        9090/TCP,8080/TCP            3m30s
service/prometheus-kube-state-metrics             ClusterIP   10.100.77.171    <none>        8080/TCP                     3m30s
service/prometheus-operated                       ClusterIP   None             <none>        9090/TCP                     2m53s
service/prometheus-prometheus-node-exporter       ClusterIP   10.105.123.252   <none>        9100/TCP                     3m30s

NAME                                                 DESIRED   CURRENT   READY   UP-TO-DATE   AVAILABLE   NODE SELECTOR            AGE
daemonset.apps/prometheus-prometheus-node-exporter   1         1         1       1            1           kubernetes.io/os=linux   3m29s

NAME                                                  READY   UP-TO-DATE   AVAILABLE   AGE
deployment.apps/prometheus-grafana                    1/1     1            1           3m29s
deployment.apps/prometheus-kube-prometheus-operator   1/1     1            1           3m29s
deployment.apps/prometheus-kube-state-metrics         1/1     1            1           3m29s

NAME                                                             DESIRED   CURRENT   READY   AGE
replicaset.apps/prometheus-grafana-6597bd8c5f                    1         1         1       3m29s
replicaset.apps/prometheus-kube-prometheus-operator-7d798c4898   1         1         1       3m29s
replicaset.apps/prometheus-kube-state-metrics-599c6b59fb         1         1         1       3m29s

NAME                                                                    READY   AGE
statefulset.apps/alertmanager-prometheus-kube-prometheus-alertmanager   1/1     2m54s
statefulset.apps/prometheus-prometheus-kube-prometheus-prometheus       1/1     2m53s
```

- deamonset is runs on every worker node



### forward port
- It will handle the direct request from localhost to kubectl pods.

#### dor graphana ui
```
kubectl port-forward deployment/prometheus-grafana 3000
```

#### for promethes ui
```
kubectl port-forward prometheus-prometheus-kube-prometheus-prometheus-0 9090
```

---
Now we are going to monitor mongodb-deployment
### mongodb-deployment.yaml
```
apiVersion: apps/v1
kind: Deployment
metadata:
  name: mongodb-depl
  labels:
    app: mongodb
spec:
  replicas: 1
  selector:
    matchLabels:
      app: mongodb
  template:
    metadata:
      labels:
        app: mongodb
    spec:
      containers:
      - name: mongodb
        image: mongo
        ports:
        - containerPort: 27017

---

apiVersion: v1
kind: Service
metadata:
  name: mongodb-service
spec:
  selector:
    app: mongodb
  ports:
    - protocol: TCP
      port: 27017
      targetPort: 27017

```

For monitoring any application like mongodb, mysql, postgres etc. we have to use exporter

Work of Exproter
- It collects the metrics data from application. 
- converts it to data understand by promethes means it expose the '/metrics' endpoint so that prometheus cascrap it.
- [Link for finding the exporter](https://prometheus.io/docs/instrumenting/exporters/)

We can write al the configuration file for the exporter and service and all the other stuf which is required or we can search for helm chart

### mongodb-exporter-values.yaml
```
mongodb:
  uri: "mongodb://mongodb-service:27017"

serviceMonitor:
  additionalLabels: 
    release: prometheus
  enabled: true

```

### Helm command for install the mongodb-export
```
helm install mongodb-exporter prometheus-community/prometheus-mongodb-exporter -f .\mongodb-exporter-values.yaml
```
