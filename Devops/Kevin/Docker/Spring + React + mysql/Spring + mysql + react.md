# Containerize Full Stack Application

- **For Springboot app to images**
```sh
./mvnw spring-boot:build-image "-Dspring-boot.build-image.imageName=kevin0403/blogvista"
```

- **For starting mysql connection**
```sh
docker run --name mysqldb --network mysql-network -e MYSQL_ROOT_PASSWORD=root -e MYSQL_DATABASE=XYZ -d mysql
```
- **For running springboot application**
```sh
docker run -d --name backend --network mysql-network -p 9090:8080 kevin0403/blogvista
```
---
- **Dockerfile for react**
```dockerfile
FROM node:latest

WORKDIR /app

COPY . .

RUN npm install

EXPOSE 8081

CMD [ "npm", "run", "dev" ]
```
---

- Build docker file 
```sh
docker build -t <file_name>:<Tagg> .
```

- Run docker file of frntend
```sh
docker run -p 8081:8081 -d --name frontend <file_name>:<Tagg>
```

- Check logs for getting url 
```sh
docker logs <conainerId | Name>
```