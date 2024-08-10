package org.example.springbootapp;


import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.HashMap;

@RestController
@RequestMapping("/")
public class HelloController {

    @GetMapping("/")
    public String hello(){
        return "hello";
    }

}
