# RBAC: Role Based Access Control
### Can be divided into two parts
- Users
- Service Accounts

## Admin
- Defines Access for users, User like:
    - QE Engineer
    - Devops Engineer
    - Etc...
- Define Access for services, by ```creating Service Account```

### RBAC can be defined as management of
- Service Account/User Account
- Roles/Cluster Roles
- Role Binding/CRB

### Kubernetes does not deal with user management, it is offloaded to External Identity Provider.

- Identity provider like
    - AWS IAM, if using AWS EKS.
- We create Service Account and Role.
    - Role: 
        - Takes care of Permissions.
        - If created in a namespace -> role
        - If in cluster -> cluster role
    - Service Account:
        - Takes care of user management.
    - Role Binding:
        - Binds Role and Service Account.


## [RBAC Video](https://youtu.be/1slRgW2IzJY?si=OUiDn75qQru_ka2C)

---
### Create Service Account
- ```kubectl create sa <service-account-name>```
- ```kubectl create token <above-service-account-name>```

### Defining Role:

```yaml
apiVersion: rbac.authorization.k8s.io/v1
kind: Role
metadata:
  namespace: default
  name: pod-reader
rules:
- apiGroups:
  - ''
  resources:
  - pods
  verbs:
  - get
  - watch
  - list
```


### Defining Role Binding:

```yaml
apiVersion: rbac.authorization.k8s.io/v1
kind: RoleBinding
metadata:
  name: read-pods
  namespace: default
subjects:
- kind: ServiceAccount
  name: mysa
  namespace: default
roleRef:
  kind: Role
  name: pod-reader
  apiGroup: rbac.authorization.k8s.io
```

### Attaching Service account with pod:

```yaml
apiVersion: v1
kind: Pod
metadata:
  name: nginx
spec:
  serviceAccountName: mysa
  containers:
  - name: nginx
    image: nginx:1.14.2
    ports:
    - containerPort: 80
```

### Verifying permissions

```shell
kubectl auth can-i get pods --as=system:serviceaccount:default:mysa
```