package com.springbook.view.controller;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class DispatcherServlet extends HttpServlet {
	/*
	private static final long serialVersionUID = 1L;
	private HandlerMapping handlerMapping;
	private ViewResolver viewResolver;
	*/
	// ���� �����̳ʰ� DispatcherServlet ��ü�� �����ϸ� �ڵ����� init() �޼ҵ尡 ����
	// init() �޼ҵ�� action-servlet.xml�� �ε��Ͽ� XmlApplicationContext�� ����, ��, ������ �����̳ʰ� ����
	// �ᱹ action-servlet.xml�� DispatcherServlet�� ����� HandlerMapping, viewResolver, Controller Ŭ������
	// <bean> ����ϸ� ������ �����̳ʰ� �ش� ��ü���� ������ �ش�.
	
	// DispatcherServlet�� Spring �����̳ʸ� ������ ��, web.xml ���Ͽ� ��ϵ� ���� �̸� �ڿ� "-servlet.xml"�� �ٿ��� ������ ���������� ã�´�.
	// ���� web.xml�� ��ϵ� DipatcherServlet�� �̸��� dispatcher ���ٸ� "/WEB-INF/dispatcher-servlet.xml" ������ ã���� ���̴�.
	// ���⼭�� action���� ��� �Ǿ� �����Ƿ� "/WEB-INF/action-servlet.xml" ������ ã�´�.
	
	// web.xml�� <init-param>�� ����Ͽ� ���� ������ ��ġ�� �̸��� �������� �� �ִ�.
	// web.xml�� ����
	// private String contextConfigLocation;
	/*
	public void init() throws ServletException {
		handlerMapping = new HandlerMapping();
		viewResolver = new viewResolver();
		viewResolver.setPrefix("./");
		viewResolver.setSuffix(".jsp");
		*/
		// web.xml�� <init-parm> ����
		/*
		 * contextConfigLocation = config.getInitParameter("contextConfigLocation");
		 * new XmlWebApplicationContext(contextConfigLocation);
		 */
//	}
}
