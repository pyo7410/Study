package com.springbook.biz;

import org.springframework.context.support.AbstractApplicationContext;
import org.springframework.context.support.GenericXmlApplicationContext;

public class TVUser {
	
	public static void main(String[] args) {
		/*
		TV tv = new SamsungTV();
		tv.powerOn();
		tv.volumeUp();
		tv.volumeDown();
		tv.powerOff();
		
		TV ltv = new LgTV();
		ltv.powerOn();
		ltv.volumeUp();
		ltv.volumeDown();
		ltv.powerOff();
		*/
		
		
		
		/*
		// 다형성 실습
		BeanFactory factory = new BeanFactory();
		// 상속이 안되어있기때문에 TV형 변환이 필요하다.
		TV bf_tv = (TV)factory.getBean(args[0]);
		bf_tv.powerOn();
		bf_tv.volumeUp();
		bf_tv.volumeDown();
		bf_tv.powerOff();
		*/
		
		
		/*
		// IOC 실습
		// 1. Spring 컨테이너를 구동한다.
		// GenericXmlApplictionContext : 파일 시스템이나 클래스 경로에 있는 XML 설정 파일을 로딩하여 구동하는 컨테이너이다.
		// XmlWebApplicationContext : 웹 기반의 스프링 애플리케이션을 개발할 때 사용하는 컨테이너이다.
		AbstractApplicationContext factory = new GenericXmlApplicationContext("applicationContext.xml");
		
		// 2. Spring 컨테이너로부터 필요한 객체를 요청(Lookup)한다.
		TV tv = (TV)factory.getBean("tv");
		tv.powerOn();
		tv.powerOff();
		tv.volumeUp();
		tv.volumeDown();
		
		// 3. Spring 컨테이너를 종료한다.
		factory.close();
		*/		
		
		
		/*
		// scope 실습, singleton,prototype 
		AbstractApplicationContext factory = new GenericXmlApplicationContext("applicationContext.xml");
		
		// 2. Spring 컨테이너로부터 필요한 객체를 요청한다.
		TV tv1 = (TV)factory.getBean("tv");
		TV tv2 = (TV)factory.getBean("tv");
		TV tv3 = (TV)factory.getBean("tv");
				
		// 3. Spring 컨테이너를 종료한다.
		factory.close();
		*/
		
		
		// Dependency Injection 실습
		/*
		AbstractApplicationContext factory = new GenericXmlApplicationContext("applicationContext.xml");
		
		TV tv = (TV)factory.getBean("tv");
		
		tv.powerOn();
		tv.volumeUp();
		tv.volumeDown();
		tv.powerOff();
		
		factory.close();
		*/
		
		// @Component 실습
		/*
		AbstractApplicationContext factory = new GenericXmlApplicationContext("applicationContext.xml");
		
		TV tv = (TV)factory.getBean("tv");
		
		tv.powerOn();
		tv.volumeUp();
		tv.volumeDown();
		tv.powerOff();
		
		factory.close();
		*/
	}

}
