<%@page import="com.springbook.biz.board.impl.BoardDAO"%>
<%@page import="com.springbook.biz.board.BoardVO"%>
<%@page contentType="text/html; charset=EUC-KR"%>

<%

	// 1. 사용자 입력 정보 추출
	// 사용자 입력 데이터에 한글이 포함되어 있으면, 사용자 입력정보를 getParameter() 메소드로 추출했을 때 한글이 깨진다.
	// 따라서 사용자 입력 정보를 추출하기 전에 반드시 setCharacterEncoding() 메소드로 한글 인코딩 처리가 필요하다.
	request.setCharacterEncoding("EUC-KR");
	String title = request.getParameter("title");
	String content = request.getParameter("content");
	String seq = request.getParameter("seq");
	
	// 2. DB 연동 처리
	BoardVO vo = new BoardVO();
	vo.setTitle(title);
	vo.setContent(content);
	vo.setSeq(Integer.parseInt(seq));
	
	BoardDAO boardDAO = new BoardDAO();
	boardDAO.updateBoard(vo);
	
	// 3. 화면 네비게이션
	response.sendRedirect("getBoardList.jsp");
	
%>