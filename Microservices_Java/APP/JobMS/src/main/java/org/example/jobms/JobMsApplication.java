package org.example.jobms;

import jakarta.annotation.Generated;
import org.example.jobms.job.LoadBalancerConfiguration;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.ImportAutoConfiguration;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.loadbalancer.annotation.LoadBalancerClients;
import org.springframework.cloud.openfeign.EnableFeignClients;
import org.springframework.cloud.openfeign.FeignAutoConfiguration;


@EnableFeignClients
@SpringBootApplication
//@ImportAutoConfiguration({FeignAutoConfiguration.class, HttpClientConfiguration.class})
//@LoadBalancerClients(defaultConfiguration = LoadBalancerConfiguration.class)
public class JobMsApplication {

	public static void main(String[] args) {
		SpringApplication.run(JobMsApplication.class, args);
	}

}
