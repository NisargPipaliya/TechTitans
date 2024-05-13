## For Springboot app to image
./mvnw spring-boot:build-image "-Dspring-boot.build-image.imageName=kevin0403/blogvista"

## For starting mysql connection
--> docker run --name mysqldb --network mysql-network -e MYSQL_ROOT_PASSWORD=root -e MYSQL_DATABASE=XYZ -d mysql

## for running springboot application
--> docker run -d --name backend --network mysql-network -p 9090:8080 kevin0403/blogvista


## Dockerfile for react

--------------------
FROM node:latest

WORKDIR /app

COPY . .

RUN npm install

EXPOSE 8081

CMD [ "npm", "run", "dev" ]
------------------------------------


# Build docker file 
--> docker build -t <file_name>:<Tagg> .

# Run docker file of frntend
--> docker run -p 8081:8081 -d --name frontend <file_name>:<Tagg>

# check logs for getting url 
--> docker logs <conainerId | Name>

