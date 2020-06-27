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
		// ������ �ǽ�
		BeanFactory factory = new BeanFactory();
		// ����� �ȵǾ��ֱ⶧���� TV�� ��ȯ�� �ʿ��ϴ�.
		TV bf_tv = (TV)factory.getBean(args[0]);
		bf_tv.powerOn();
		bf_tv.volumeUp();
		bf_tv.volumeDown();
		bf_tv.powerOff();
		*/
		
		
		/*
		// IOC �ǽ�
		// 1. Spring �����̳ʸ� �����Ѵ�.
		// GenericXmlApplictionContext : ���� �ý����̳� Ŭ���� ��ο� �ִ� XML ���� ������ �ε��Ͽ� �����ϴ� �����̳��̴�.
		// XmlWebApplicationContext : �� ����� ������ ���ø����̼��� ������ �� ����ϴ� �����̳��̴�.
		AbstractApplicationContext factory = new GenericXmlApplicationContext("applicationContext.xml");
		
		// 2. Spring �����̳ʷκ��� �ʿ��� ��ü�� ��û(Lookup)�Ѵ�.
		TV tv = (TV)factory.getBean("tv");
		tv.powerOn();
		tv.powerOff();
		tv.volumeUp();
		tv.volumeDown();
		
		// 3. Spring �����̳ʸ� �����Ѵ�.
		factory.close();
		*/		
		
		
		/*
		// scope �ǽ�, singleton,prototype 
		AbstractApplicationContext factory = new GenericXmlApplicationContext("applicationContext.xml");
		
		// 2. Spring �����̳ʷκ��� �ʿ��� ��ü�� ��û�Ѵ�.
		TV tv1 = (TV)factory.getBean("tv");
		TV tv2 = (TV)factory.getBean("tv");
		TV tv3 = (TV)factory.getBean("tv");
				
		// 3. Spring �����̳ʸ� �����Ѵ�.
		factory.close();
		*/
		
		
		// Dependency Injection �ǽ�
		/*
		AbstractApplicationContext factory = new GenericXmlApplicationContext("applicationContext.xml");
		
		TV tv = (TV)factory.getBean("tv");
		
		tv.powerOn();
		tv.volumeUp();
		tv.volumeDown();
		tv.powerOff();
		
		factory.close();
		*/
		
		// @Component �ǽ�
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
