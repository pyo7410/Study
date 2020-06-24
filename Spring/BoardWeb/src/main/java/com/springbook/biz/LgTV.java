package com.springbook.biz;

import javax.annotation.Resource;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.stereotype.Component;

//@Component("tv")
public class LgTV implements TV {
	
	/*
	@Autowired
	@Qualifier("apple") // 의존성 주입될 객체의 아이디나 이름을 지정하여 처리가능하다.
	// 이 예제의 경우 SonySpeaker와 AppleSpeaker가 Speaker를 상속받고 있어 Autowired로는 어떤 둘중 어떤 객체를 받아야하는지 알 수가 없기 떄문에
	// 꼭 필요하다
	private Speaker speaker;
	*/
	
	/*
	@Resource(name="apple")
	// name 속성을 사용하여, 해당 이름으로 생성된 객체를 검색하여 의존성 주입을 처리한다.
	// Autowired + Qaulifier
	private Speaker speaker;
	*/
	
	// 어노테이션과 XML 설정 병행 실습
	// 클라이언트가 요청할 LgTV는 @Component로 처리하고 의존성 주입역시 @Autowired로 처리
	// 변경될 Speaker만 bean에 등록하여 자바 코드 수정 없이 XML 수정만으로 Speaker를 교체 가능
	// 즉, 변경되지 않는 객체는 어노테이션을 설정하고 변경될 가능성이 있는 객체는 XML 설정으로 사용
	@Autowired
	private Speaker speaker;
	
	public LgTV() {
		System.out.println("===> LgTV 객체 생성");
	}
	public void powerOn() {
		System.out.println("LgTV---전원 켠다.");
	}
	public void powerOff() {
		System.out.println("LgTV---전원 끈다.");
	}
	public void volumeUp() {
		//System.out.println("LgTV---소리 올린다.");
		speaker.volumeUp();
	}
	public void volumeDown() {
		//System.out.println("LgTV---소리 내린다.");
		speaker.volumeDown();
	}

}
