# Actuator
- Add Actuator dependency to project.
- add ```/actuator``` to base path when running the project to see the endpoints provided by Actuator.

```yaml
# Below property is added so that we can access all the endpoint provided by actuator.
management.endpoints.web.exposure.include=*

# Config for /health endpoint
management.endpoint.health.show-details=always

# Config for /info endpoint
management.info.env.enabled=true
info.app.name=JobApp
info.app.description=AppByNisarg

# To enable shutdown endpoint
management.endpoint.shutdown.enabled=true


# Making shutdown graceful
server.shutdown=graceful
```

## Endpoints:

|Endpoint | Purpose|
|---------|--------|
| /health  | Shows application health information, useful for checking the status of the application,such as database connectivity, disk space, and custom health checks.|
|/info | Displays arbitrary application information, commonly used to display application version, git commit information, etc.|
|/metrics|Shows 'metrics' information that allows you to understand the performance and behavior of your running application.|
|/loggers | Allows you to query and modify the logging level of your application's loggers.|
|/beans | Provides a complete list of all the Spring beans in your application|
|/shutdown |Allows your application to be gracefully shut down, i.e. if there are any ongoing requests then it will complete it and then shutdown it self. It only support **Post** request.|


## Changing Logging Level
- Go to ```/loggers``` endpoint.
- Then Select an endpoint name, and create a **POST** request
```json
{
    "configurationLevel":"LEVEL_NAME"
}
```
