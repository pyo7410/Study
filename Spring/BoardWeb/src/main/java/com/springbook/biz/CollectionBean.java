package com.springbook.biz;

import java.util.List;
import java.util.Map;
import java.util.Set;

public class CollectionBean {
	/*
	// �迭 ��ü�� �÷��� ��ü�� List ���
	private List<String> addressList;
	
	public void setAddressList(List<String> addressList) {
		this.addressList = addressList;
	}
	public List<String> getAddressList() {
		return addressList;
	}
	*/
	
	/*
	// �ߺ� ���� ������� �ʴ� ���� ��ü�� List�� �ƴ� Set�� ����Ѵ�.
	private Set<String> addressList;
	
	public void setAddressList(Set<String> addressList) {
		this.addressList = addressList;
	}
	public Set<String> getAddressList() {
		return addressList;
	}
	*/
	
	// Ư�� Key�� �����ͷ� ����ϰ� ����� ���� Map�� ���
	private Map<String, String> addressList;
	
	public void setAddressList(Map<String, String> addressList) {
		this.addressList = addressList;
	}
	public Map<String, String> getAddressList() {
		return addressList;
	}
}
