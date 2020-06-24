package com.springbook.biz;

import java.util.List;
import java.util.Map;
import java.util.Set;

import org.springframework.context.support.AbstractApplicationContext;
import org.springframework.context.support.GenericXmlApplicationContext;

public class CollectionBeanClient {

	public static void main(String[] args) {
		AbstractApplicationContext factory = new GenericXmlApplicationContext("applicationContext.xml");
		
		CollectionBean bean = (CollectionBean)factory.getBean("collectionBean");
		// List
		// List<String> addressList = bean.getAddressList();
		// Set
		// Set<String> addressList = bean.getAddressList();
		// Map
		Map<String, String> addressList = bean.getAddressList();
		/*for (String address : addressList) {
			System.out.println(address.toString());
		}
		factory.close();*/
	}
	
}
