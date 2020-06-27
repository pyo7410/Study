package com.springbook.biz;

public class SamsungTV implements TV {
	
	// Dependency Injection �ǽ�
	// private SonySpeaker speaker;
	// �������� ���� �ǽ�
	private Speaker speaker;
	
	private int price;
	
	// applicationContext.xml�� init-method, destroy-method�� ó��
	// initMethod() : �����̳ʰ� �����Ǿ� SamsungTV ��ü�� ������ ���Ŀ� ȣ��
	// destroyMethod() : SamsungTV ��ü�� �����Ǳ� ������ ȣ��
	public void initMethod() {
		System.out.println("��ü �ʱ�ȭ �۾� ó��..");
	}
	public void destroyMethod() {
		System.out.println("��ü ���� ���� ó���� ���� ó��...");
	}
	
	public SamsungTV() {
		System.out.println("===> SamsungTV ��ü ����");
	}
	// Dependency Injection �ǽ�
	// public SamsungTV(SonySpeaker speaker) {
	// ���� ���� ���� �ǽ�
	public SamsungTV(Speaker speaker) {
		System.out.println("===> SamsungTV(2) ��ü ����");
		this.speaker = speaker;
	}
	// public SamsungTV(SonySpeaker speaker, int price) {
	// ���� ���� ���� �ǽ�
	public SamsungTV(Speaker speaker, int price) {
		System.out.println("===> SamsungTV(3) ��ü ����");
		this.speaker = speaker;
		this.price = price;
	}
	
	// Setter ������ �ǽ�
	public void setSpeaker(Speaker speaker) {
		System.out.println("===> setSpeaker() ȣ��");
		this.speaker = speaker;
	}
	public void setPrice(int price) {
		System.out.println("===> setPrice() ȣ��");
		this.price = price;
	}
	
	
	public void powerOn() {
		//System.out.println("SamsungTV---���� �Ҵ�.");
		
		// Dependency Injection �ǽ�
		System.out.println("SamsungTV---���� �Ҵ�. (���� : " + price + ")");
	}
	public void powerOff() {
		System.out.println("SamsungTV---���� ����.");
	}
	public void volumeUp() {
		//System.out.println("SamsungTV---�Ҹ� �ø���.");
		
		/*
		// Dependency Injection �ǽ�
		speaker = new SonySpeaker();
		speaker.volumeUp();
		*/
		
		// Dependency Injection �ǽ�
		speaker.volumeUp();
	}
	public void volumeDown() {
		//System.out.println("SamsungTV---�Ҹ� ������.");
		
		/*
		// Dependency Injection �ǽ�
		speaker = new SonySpeaker();
		speaker.volumeDown();
		*/
		
		// Dependency Injection �ǽ�
		speaker.volumeDown();
	}

}
