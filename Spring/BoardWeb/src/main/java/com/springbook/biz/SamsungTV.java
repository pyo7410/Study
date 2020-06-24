package com.springbook.biz;

public class SamsungTV implements TV {
	
	// Dependency Injection 실습
	// private SonySpeaker speaker;
	// 의존관계 변경 실습
	private Speaker speaker;
	
	private int price;
	
	// applicationContext.xml의 init-method, destroy-method의 처리
	// initMethod() : 컨테이너가 구동되어 SamsungTV 객체가 생성된 직후에 호출
	// destroyMethod() : SamsungTV 객체가 삭제되기 직전에 호출
	public void initMethod() {
		System.out.println("객체 초기화 작업 처리..");
	}
	public void destroyMethod() {
		System.out.println("객체 삭제 전에 처리할 로직 처리...");
	}
	
	public SamsungTV() {
		System.out.println("===> SamsungTV 객체 생성");
	}
	// Dependency Injection 실습
	// public SamsungTV(SonySpeaker speaker) {
	// 의존 관계 변경 실습
	public SamsungTV(Speaker speaker) {
		System.out.println("===> SamsungTV(2) 객체 생성");
		this.speaker = speaker;
	}
	// public SamsungTV(SonySpeaker speaker, int price) {
	// 의존 관계 변경 실습
	public SamsungTV(Speaker speaker, int price) {
		System.out.println("===> SamsungTV(3) 객체 생성");
		this.speaker = speaker;
		this.price = price;
	}
	
	// Setter 인젝션 실습
	public void setSpeaker(Speaker speaker) {
		System.out.println("===> setSpeaker() 호출");
		this.speaker = speaker;
	}
	public void setPrice(int price) {
		System.out.println("===> setPrice() 호출");
		this.price = price;
	}
	
	
	public void powerOn() {
		//System.out.println("SamsungTV---전원 켠다.");
		
		// Dependency Injection 실습
		System.out.println("SamsungTV---전원 켠다. (가격 : " + price + ")");
	}
	public void powerOff() {
		System.out.println("SamsungTV---전원 끈다.");
	}
	public void volumeUp() {
		//System.out.println("SamsungTV---소리 올린다.");
		
		/*
		// Dependency Injection 실습
		speaker = new SonySpeaker();
		speaker.volumeUp();
		*/
		
		// Dependency Injection 실습
		speaker.volumeUp();
	}
	public void volumeDown() {
		//System.out.println("SamsungTV---소리 내린다.");
		
		/*
		// Dependency Injection 실습
		speaker = new SonySpeaker();
		speaker.volumeDown();
		*/
		
		// Dependency Injection 실습
		speaker.volumeDown();
	}

}
