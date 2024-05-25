### Docker command for zipkin
```
docker run -d -p 9411:9411 openzipkin/zipkin
```


### Required Dependances

```
        <dependency>
            <groupId>io.micrometer</groupId>
            <artifactId>micrometer-tracing-bridge-brave</artifactId>
        </dependency>
        <dependency>
            <groupId>io.zipkin.reporter2</groupId>
            <artifactId>zipkin-reporter-brave</artifactId>
        </dependency>

        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-actuator</artifactId>
        </dependency>

        <dependency>
            <groupId>io.github.openfeign</groupId>
            <artifactId>feign-micrometer</artifactId>
            <version>13.2.1</version>
        </dependency>
```

### Application.properties

```
management.tracing.sampling.probability=1.0
```

### compose file configuration

```
version: "3.8"
services:
  postgres:
    image: postgres
    container_name: postgres_container
    restart: unless-stopped
    ports:
      - "5432:5432"
    environment:
      POSTGRES_USER: admin
      POSTGRES_PASSWORD: admin
    volumes:
      - local_pgdata:/var/lib/postgresql/data
    networks:
      - postgres

  pgadmin:
    image: dpage/pgadmin4
    container_name: pgadmin4_container
    restart: always
    ports:
      - "5050:80"
    environment:
      PGADMIN_DEFAULT_EMAIL: ${PGADMIN_DEFAULT_EMAIL:-pgadmin4@pgadmin.org}
      PGADMIN_DEFAULT_PASSWORD: ${PGADMIN_DEFAULT_PASSWORD:-admin}
      PGADMIN_CONFIG_SERVER_MODE: 'False'
    volumes:
      - pgadmin-data:/var/lib/pgadmin
    networks:
      - postgres
  zipkin:
    image: openzipkin/zipkin
    container_name: zipkin
    ports:
      - 9411:9411
    networks:
      - postgres
networks:
  postgres:
    driver: bridge

volumes:
  local_pgdata:
  pgadmin-data:

```
