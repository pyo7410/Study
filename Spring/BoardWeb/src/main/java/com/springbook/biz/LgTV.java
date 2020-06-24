package com.springbook.biz;

import javax.annotation.Resource;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.stereotype.Component;

//@Component("tv")
public class LgTV implements TV {
	
	/*
	@Autowired
	@Qualifier("apple") // ������ ���Ե� ��ü�� ���̵� �̸��� �����Ͽ� ó�������ϴ�.
	// �� ������ ��� SonySpeaker�� AppleSpeaker�� Speaker�� ��ӹް� �־� Autowired�δ� � ���� � ��ü�� �޾ƾ��ϴ��� �� ���� ���� ������
	// �� �ʿ��ϴ�
	private Speaker speaker;
	*/
	
	/*
	@Resource(name="apple")
	// name �Ӽ��� ����Ͽ�, �ش� �̸����� ������ ��ü�� �˻��Ͽ� ������ ������ ó���Ѵ�.
	// Autowired + Qaulifier
	private Speaker speaker;
	*/
	
	// ������̼ǰ� XML ���� ���� �ǽ�
	// Ŭ���̾�Ʈ�� ��û�� LgTV�� @Component�� ó���ϰ� ������ ���Կ��� @Autowired�� ó��
	// ����� Speaker�� bean�� ����Ͽ� �ڹ� �ڵ� ���� ���� XML ���������� Speaker�� ��ü ����
	// ��, ������� �ʴ� ��ü�� ������̼��� �����ϰ� ����� ���ɼ��� �ִ� ��ü�� XML �������� ���
	@Autowired
	private Speaker speaker;
	
	public LgTV() {
		System.out.println("===> LgTV ��ü ����");
	}
	public void powerOn() {
		System.out.println("LgTV---���� �Ҵ�.");
	}
	public void powerOff() {
		System.out.println("LgTV---���� ����.");
	}
	public void volumeUp() {
		//System.out.println("LgTV---�Ҹ� �ø���.");
		speaker.volumeUp();
	}
	public void volumeDown() {
		//System.out.println("LgTV---�Ҹ� ������.");
		speaker.volumeDown();
	}

}
