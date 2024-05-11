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