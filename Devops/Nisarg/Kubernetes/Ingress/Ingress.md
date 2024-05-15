## What is Ingress?
- When we use external service to make our app accessible, we expose it as IP:Port.
- But it should be accessible using human readable name like ``` myapp.com```.
- For this we use Ingress,
    - User will write human readable url, it will be sent to Ingress.
    - Ingress will forward it to Internal service of app.
    - Which will forward it to Pod running over there.
- For this to work, we need Ingress-controller, which will,
    - Evaluate routing rules
    - Manages redirections 
    - Act as entrypoint to cluster
- Ingress Controller has many third party impl
    - One is K8s Nginx Ingress Controller


## Ingress on Minikube

```shell
minikube addons enable ingress
minikube addons enable ingress-dns
```
- To check ingress controller pod is running or not?
```shell
kubectl get pods -n ingress-nginx
```

## Follow below commands
```shell
minikube status
minikube dashboard
#(exit dashboard)
kubectl get all -n kubernetes-dashboard
```

- Ingress File for dashboard
```yaml
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

- ``` kubectl get ingress -n kubernetes-dashboard```
- After executing the file, add ``` 127.0.0.1 host-name ``` to your **host** file in home/windws32/drivers/etc/.
- Then execute ```minikube tunnel``` and wait until cursor dosen't blink.
- Now type host name in browser, and it will work.
- Refer This: [StackOverFlow Article](https://stackoverflow.com/questions/58561682/minikube-with-ingress-example-not-working)