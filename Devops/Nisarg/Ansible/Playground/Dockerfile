FROM ubuntu:latest

# Install basic net tools
RUN apt-get update
RUN apt-get install -y openssh-server pwgen 
RUN apt-get clean all
RUN apt-get install -y vim

# Set localtime
RUN ln -sf /usr/share/zoneinfo/Europe/Warsaw /etc/localtime
RUN mkdir /var/run/sshd

# SSH connected stuff
RUN sed -ri 's/^PermitRootLogin\s+.*/PermitRootLogin yes/' /etc/ssh/sshd_config
RUN sed -ri 's/UsePAM yes/#UsePAM yes/g' /etc/ssh/sshd_config

# Copy keys
# RUN mkdir /root/.ssh
COPY ./keys/ansible_key.pub /root/.ssh/authorized_keys.pub
RUN chmod 400 /root/.ssh/authorized_keys.pub

# Expose port
EXPOSE 22
CMD ["/usr/sbin/sshd", "-D"]