## Pull Mongo DB Image
    docker pull mongo
    docker pull mongo-express

## Create Docker Network
    docker network ls
    docker network create mongo-net

## Run Containers in Network Created
    docker run -d -p 27017:27017  -e MONGO_INITDB_ROOT_USERNAME=admin -e MONGO_INITDB_ROOT_PASSWORD=password --name mongodb --net mongo-net mongo

    docker run -d -p 8081:8081  -e ME_CONFIG_MONGODB_ADMINUSERNAME=admin -e ME_CONFIG_MONGODB_ADMINPASSWORD=password  -e ME_CONFIG_MONGODB_SERVER=mongodb (it is container name)  --name mongo-express --net mongo-net mongo-express
(can also specify env variables for mongo when starting a container using "-e")


## Install node packages and run
    npm i 
    node server.js


## Image name
docker_domain_registery/image_name:tag
