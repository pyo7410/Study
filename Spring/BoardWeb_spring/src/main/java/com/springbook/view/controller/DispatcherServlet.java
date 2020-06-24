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
	// 서블릿 컨테이너가 DispatcherServlet 객체를 생성하면 자동으로 init() 메소드가 실행
	// init() 메소드는 action-servlet.xml을 로딩하여 XmlApplicationContext를 생성, 즉, 스프링 컨테이너가 구동
	// 결국 action-servlet.xml에 DispatcherServlet이 사용할 HandlerMapping, viewResolver, Controller 클래스를
	// <bean> 등록하면 스프링 컨테이너가 해당 객체들을 생성해 준다.
	
	// DispatcherServlet은 Spring 컨테이너를 구동할 때, web.xml 파일에 등록된 서블릿 이름 뒤에 "-servlet.xml"을 붙여서 스프링 설정파일을 찾는다.
	// 따라서 web.xml에 등록된 DipatcherServlet의 이름이 dispatcher 였다면 "/WEB-INF/dispatcher-servlet.xml" 파일을 찾았을 것이다.
	// 여기서는 action으로 등록 되어 있으므로 "/WEB-INF/action-servlet.xml" 파일을 찾는다.
	
	// web.xml의 <init-param>을 사용하여 설정 파일의 위치와 이름을 설정해줄 수 있다.
	// web.xml을 참고
	// private String contextConfigLocation;
	/*
	public void init() throws ServletException {
		handlerMapping = new HandlerMapping();
		viewResolver = new viewResolver();
		viewResolver.setPrefix("./");
		viewResolver.setSuffix(".jsp");
		*/
		// web.xml의 <init-parm> 참고
		/*
		 * contextConfigLocation = config.getInitParameter("contextConfigLocation");
		 * new XmlWebApplicationContext(contextConfigLocation);
		 */
//	}
}
