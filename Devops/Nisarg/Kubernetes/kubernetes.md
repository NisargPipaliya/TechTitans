## Install minikube and kubectl
- docker context use default
- winget install kubectl
- winget install minikube
- winget install kubectx
- winget install Helm.Helm
- minikube addons enable metrics-server
- minikube addons enable ingress

### Start Minikube
- minikube start --driver=docker (will download around 700mb files)

### Kubectl commands
- kubectl get pod
- kubectl run pod-name --image=image_from_which_pod_is_to_be_created:tag   (If local image) --image-pull-policy=Never (If local image) --restart=Never
- kubectl delete pod pod-name
- kubectl get services
- kubectl get deployment
- kubectl get all  // gets all components
- kubectl create deployment mongo-depl --image=mongo  (Creates a deployment named as "mongo-depl" for docker image mongo)
- minikube image load local_image_name:tag  // Loads Local Image to minikube, to create pod from it.
- minikube image rm image_name // remove image from minikube.

- We will deal with deployment and not pods directly.

- kubectl get replicaset  (Replicaset is created automatically when we create deployment)
- kubectl edit deployment deployment-name (Opens deployment file for editing purpose, if edited, then old pod and replicaset will be deleted and new deployment will be created.)

- kubectl logs pod-name
- kubectl describe pod pod-name
- kubectl exec -it pod-name -- bin/bash
- kubectl delete deployment deployment-name

### Metrics
- kubectl top 
    - The kubectl top command returns current CPU and memory usage for a cluster’s pods or nodes, or for a particular pod or node if specified.

### Config file
- kubectl apply -f config-file.yaml


```
Deployment
----------
    |
  manages
    |
Replicasets
----------
    |
  manages
    |
   Pods
----------
    |
  manages
    |
 Docker Image
---------------

Everything below deployment is managed by Kubernetes
```

![alt text](image.png)

![alt text](image-1.png)