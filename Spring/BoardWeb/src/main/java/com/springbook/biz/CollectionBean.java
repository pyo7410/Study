package com.springbook.biz;

import java.util.List;
import java.util.Map;
import java.util.Set;

public class CollectionBean {
	/*
	// 배열 객체나 컬렉션 객체는 List 사용
	private List<String> addressList;
	
	public void setAddressList(List<String> addressList) {
		this.addressList = addressList;
	}
	public List<String> getAddressList() {
		return addressList;
	}
	*/
	
	/*
	// 중복 값을 허용하지 않는 집합 객체는 List가 아닌 Set을 사용한다.
	private Set<String> addressList;
	
	public void setAddressList(Set<String> addressList) {
		this.addressList = addressList;
	}
	public Set<String> getAddressList() {
		return addressList;
	}
	*/
	
	// 특정 Key를 데이터로 등록하고 사용할 떄는 Map을 사용
	private Map<String, String> addressList;
	
	public void setAddressList(Map<String, String> addressList) {
		this.addressList = addressList;
	}
	public Map<String, String> getAddressList() {
		return addressList;
	}
}
